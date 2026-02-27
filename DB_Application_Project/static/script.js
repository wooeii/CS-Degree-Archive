// DOM이 준비되었을 때 실행되는 코드
document.addEventListener("DOMContentLoaded", function () {

    // 1. 필터링 기능: 선거구를 선택한 후 데이터 동적 로딩
    const filterForm = document.querySelector("form"); // 필터링 폼 요소를 가져옴
    const electionAreaSelect = document.getElementById("election_area"); // 선거구 선택 드롭다운

    // 필터링 폼이 존재할 경우 이벤트 리스너 추가
    if (filterForm) {
        filterForm.addEventListener("submit", function (e) {
            e.preventDefault(); // 폼의 기본 제출 동작을 방지
            const electionArea = electionAreaSelect.value; // 선택된 선거구 값 가져오기
            loadFilteredData(electionArea); // 필터링된 데이터 로딩 함수 호출
        });
    }

    // 2. 후보자 상세보기 페이지로 이동하기 전에 간단한 애니메이션 처리
    const candidateLinks = document.querySelectorAll('a[href^="/view"]'); // "/view"로 시작하는 모든 링크 선택
    candidateLinks.forEach(link => {
        link.addEventListener('click', function (e) {
            e.preventDefault();  // 기본 링크 클릭 동작을 막음
            const candidateId = this.href.split('=')[1]; // URL에서 후보자 ID 추출

            // 상세보기로 이동하기 전에 로딩 인디케이터 표시
            showLoadingIndicator();

            // 1초 후에 페이지 이동 (애니메이션 효과)
            setTimeout(() => {
                window.location.href = this.href; // 해당 링크로 이동
            }, 1000);
        });
    });

    // 3. 동적 데이터 로딩 함수: 필터링된 결과를 동적으로 갱신
    function loadFilteredData(electionArea) {
        const tableBody = document.querySelector("tbody"); // 테이블의 <tbody> 요소 선택
        showLoadingIndicator();  // 로딩 인디케이터 표시

        // 서버에 필터링 요청 보내기
        fetch(`/filter?election_area=${electionArea}`)
            .then(response => response.json()) // 응답을 JSON 형식으로 변환
            .then(data => {
                // 기존 테이블 내용 삭제
                tableBody.innerHTML = '';

                // 새 데이터로 테이블 채우기
                data.forEach(row => {
                    const tr = document.createElement('tr'); // 새로운 행 생성
                    tr.innerHTML = `
                        <td>${row.id}</td>
                        <td>${row.election_area}</td>
                        <td>${row.district}</td>
                        <td>${row.candidate_name}</td>
                        <td>${row.votes_received}</td>
                        <td>${row.vote_percentage}%</td>
                        <td><a href="/view?id=${row.id}">상세보기</a></td>
                    `; // 새로운 행에 데이터 추가
                    tableBody.appendChild(tr); // 테이블에 행 추가
                });

                hideLoadingIndicator();  // 로딩 인디케이터 숨기기
            })
            .catch(error => {
                console.error("Error loading filtered data:", error); // 에러 로그 출력
                hideLoadingIndicator();  // 에러 발생 시 로딩 인디케이터 숨기기
            });
    }

    // 4. 로딩 인디케이터 표시 함수
    function showLoadingIndicator() {
        const loader = document.createElement('div'); // 새로운 div 요소 생성
        loader.className = 'loading-indicator'; // 클래스 이름 설정
        loader.textContent = '로딩 중...'; // 텍스트 추가
        document.body.appendChild(loader); // body에 로딩 인디케이터 추가
    }

    // 5. 로딩 인디케이터 숨기기 함수
    function hideLoadingIndicator() {
        const loader = document.querySelector('.loading-indicator'); // 로딩 인디케이터 선택
        if (loader) {
            loader.remove(); // 로딩 인디케이터 제거
        }
    }

});