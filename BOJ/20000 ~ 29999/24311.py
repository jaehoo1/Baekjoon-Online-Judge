from datetime import datetime, time, timedelta

t1, t2 = map(int, input().split())
t3 = int(input())
t4, t5 = map(int, input().split())
br = int(input())
t6 = int(input())

start_time = datetime.combine(datetime.today(), time(t1, t2))
start_time -= timedelta(minutes=10)
start_time -= timedelta(minutes=t3)
start_time -= timedelta(hours=t4, minutes=t5)
start_time -= timedelta(minutes=(br + 1) * t6)
print(start_time.strftime("%H %M"))