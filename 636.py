class Record(object):
    def __init__(self, record_text):
        split_record = record_text.split(':')
        self.pid = int(split_record[0])
        self.state = split_record[1]
        self.timestamp = int(split_record[2])


def exclusiveTime(n: int, logs: list) -> list:
    # Convert input logs to records
    record_list = []
    for log in logs:
        record_list.append(Record(log))

    time_record = [0] * n
    # Each element: pid, start timestamp, accumulated time
    call_stack = []
    last_end_time = 0
    for record in record_list:
        if record.state == 'start':
            if len(call_stack) != 0:
                # In this cycle, the function is already running
                call_stack[-1][2] += record.timestamp - call_stack[-1][1]
                call_stack[-1][1] = None
            call_stack.append([record.pid, record.timestamp, 0])
        else:
            last = call_stack.pop()
            last[2] += record.timestamp - last[1] + 1
            time_record[last[0]] += last[2]

            # Last function will restart at next time cycle
            if len(call_stack) != 0:
                call_stack[-1][1] = record.timestamp + 1

    return time_record

