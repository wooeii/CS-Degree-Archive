from flask import Flask, render_template, request, jsonify  # Flask 및 관련 모듈 가져오기
import pymysql  # MySQL 데이터베이스 연결을 위해 pymysql 모듈 가져오기

# Flask 애플리케이션 객체 생성
app = Flask(__name__)

# 데이터베이스 연결 설정
db = pymysql.connect(
    host="localhost",        # 데이터베이스 호스트 주소
    port=3306,               # MySQL 기본 포트 번호
    user="root",             # 데이터베이스 사용자 이름
    passwd="0000",           # 데이터베이스 비밀번호
    db="ElectionDB",         # 연결할 데이터베이스 이름
    charset="utf8"           # 문자 인코딩 설정
)
cur = db.cursor()  # 데이터베이스 작업을 위한 커서 객체 생성

# 기본 페이지: 후보 목록
@app.route('/')  # 루트 URL에 대한 라우트 설정
def index():
    # 데이터베이스에서 선거 후보 목록을 가져오는 SQL 쿼리
    sqlstring = """
        SELECT id, election_area, district, candidate_name, 
               votes_received, vote_percentage 
        FROM election_data
    """
    cur.execute(sqlstring)  # SQL 쿼리 실행
    election_list = cur.fetchall()  # 쿼리 결과를 모두 가져오기
    # HTML 템플릿 'election_list.html'을 렌더링하고 데이터 전달
    return render_template('election_list.html', election_list=election_list)

# 후보 상세 정보 페이지
@app.route('/view')  # '/view' URL에 대한 라우트 설정
def view_candidate():
    candidate_id = request.args.get('id')  # URL의 'id' 파라미터 값 가져오기
    # 특정 후보의 상세 정보를 가져오는 SQL 쿼리
    sqlstring = f"SELECT * FROM election_data WHERE id={candidate_id}"
    cur.execute(sqlstring)  # SQL 쿼리 실행
    candidate = cur.fetchone()  # 쿼리 결과에서 한 행 가져오기
    # HTML 템플릿 'election_view.html'을 렌더링하고 데이터 전달
    return render_template('election_view.html', candidate=candidate)

# 선거구별 필터링 (JSON 반환)
@app.route('/filter')  # '/filter' URL에 대한 라우트 설정
def filter_results():
    election_area = request.args.get('election_area')  # URL의 'election_area' 파라미터 값 가져오기
    # 특정 선거구의 후보 목록을 가져오는 SQL 쿼리
    sqlstring = f"""
        SELECT id, election_area, district, candidate_name, 
               votes_received, vote_percentage 
        FROM election_data WHERE election_area='{election_area}'
    """
    cur.execute(sqlstring)  # SQL 쿼리 실행
    filtered_list = cur.fetchall()  # 쿼리 결과를 모두 가져오기
    
    # 쿼리 결과를 JSON 형식으로 변환
    results = []
    for row in filtered_list:  # 결과 행 각각에 대해
        results.append({
            'id': row[0],                   # 후보 고유 번호
            'election_area': row[1],        # 선거구 이름
            'district': row[2],             # 구/시/군 이름
            'candidate_name': row[3],       # 후보 이름
            'votes_received': row[4],       # 득표 수
            'vote_percentage': row[5]       # 득표율
        })
    
    return jsonify(results)  # JSON 응답 반환

# 애플리케이션 실행
if __name__ == '__main__':  # 이 스크립트가 메인 프로그램으로 실행될 때
    app.run('0.0.0.0', port=5000)  # 0.0.0.0 주소에서 5000번 포트로 Flask 애플리케이션 실행