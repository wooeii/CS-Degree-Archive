import os
from openai import OpenAI
from dataclasses import dataclass
import pytz
from datetime import datetime, timedelta
import random

@dataclass(frozen=True)
class Model: 
    basic: str = "gpt-3.5-turbo-1106"
    advanced: str = "gpt-4-1106-preview"

model = Model();    
client = OpenAI(api_key=os.getenv("OPENAI_API_KEY"), timeout=30, max_retries=1)

def makeup_response(message, finish_reason="ERROR"):
    return {
                "choices": [
                    {
                        "finish_reason": finish_reason,
                        "index": 0,
                        "message": {
                            "role": "assistant",
                            "content": message
                        }                   
                    }
                ],
                "usage": {"total_tokens": 0},
            }

def today():
    korea = pytz.timezone('Asia/Seoul')
    now = datetime.now(korea)
    return now.strftime("%Y%m%d")

def yesterday():    
    korea = pytz.timezone('Asia/Seoul')
    now = datetime.now(korea)
    one_day = timedelta(days=1)
    yesterday = now - one_day
    return yesterday.strftime('%Y%m%d')

def currTime():
    korea = pytz.timezone('Asia/Seoul')
    now = datetime.now(korea)
    return now.strftime("%Y.%m.%d %H:%M:%S")

def fetch_genre_mood_recommendations(genre=None, mood=None):
    music_library = {
        "pop": {
            "happy": ["Happy - Pharrell Williams", "Uptown Funk - Bruno Mars"],
            "sad": ["Someone Like You - Adele", "All of Me - John Legend"]
        },
        "rock": {
            "energetic": ["Eye of the Tiger - Survivor", "Smells Like Teen Spirit - Nirvana"],
            "calm": ["Nothing Else Matters - Metallica", "Tears in Heaven - Eric Clapton"]
        },
    }
    
    if genre and mood:
        return music_library.get(genre, {}).get(mood, ["해당 조건에 맞는 음악이 없습니다."])
    elif genre:
        return list(random.choice(list(music_library.get(genre, {}).values())))
    elif mood:
        return [song for genre in music_library.values() for mood_songs in genre.values() if mood in mood_songs]
    else:
        return ["추천할 음악을 찾을 수 없습니다."] 
