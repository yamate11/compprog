#!/usr/bin/env python3

import subprocess
import signal

with subprocess.Popen(['./subproc'], encoding='UTF-8',
                      stdin=subprocess.PIPE, stdout=subprocess.PIPE) as proc:
    try:
        for s in ['100', '200', 'sss']:
            print(s, file=proc.stdin, flush=True)
            line = proc.stdout.readline()
            print(f'{int(line) * 1.1}')
    finally:
        proc.send_signal(signal.SIGTERM)
                        
