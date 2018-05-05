import datetime


def nextClosestTime(time):
    usable_digits = set(digit for digit in time if digit != ':')
    target_time = datetime.datetime.strptime(time, '%H:%M')
    result = None
    time_delta = datetime.timedelta(days=100).total_seconds()
    for t0 in usable_digits:
        for t1 in usable_digits:
            for t2 in usable_digits:
                for t3 in usable_digits:
                    try:
                        current_time = datetime.datetime.strptime('{}{}:{}{}'.format(t0, t1, t2, t3), '%H:%M')
                    except ValueError:
                        # Not a valid time
                        continue
                    time_diff = (current_time - target_time).total_seconds()
                    if time_diff <= 0:
                        current_time += datetime.timedelta(days=1)
                        time_diff = (current_time - target_time).total_seconds()
                    if time_diff < time_delta:
                        time_delta = time_diff
                        result = current_time

    return result.strftime('%H:%M')
