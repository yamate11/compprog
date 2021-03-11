import os, subprocess, sys

def warn(*msg):
    print(*msg, file=sys.stderr, flush=True)

def die(msg):
    warn('ERROR: ' + msg)
    sys.exit(1)

class UtilError(Exception):
    pass

class Util:
    fDP = "./double-prec"

    @staticmethod
    def get_prec(prec, rewrite):
        '''Get precision for comparing doubles.

The precision is taken from argument prec and the contents of
the file named "./double-prec", with higher preference in argument prec.
If rewrite is True, the file is overwritten with prec if it is not None.
'''
        if prec is None:
            if os.path.exists(Util.fDP):
                with open(Util.fDP) as fp:
                    try:
                        n = float(fp.readline())
                    except TypeError:
                        msg = f'{Util.fDP} does not have a number.'
                        raise UtilError(msg)
                    if n <= 0:
                        msg = f'Contents of {Util.fDP} is not positive.'
                        raise UtilError(msg)
                    return n
            else:
                return None
        else:
            if prec <= 0:
                raise UtilError('Specified precision is not positive.')
            if rewrite:
                with open(Util.fDP, 'w') as wfp:
                    print(prec, file=wfp)
            return prec

    @staticmethod
    def compare_answer(ans1, ans2, prec=None, ignoreSpace=False):
        '''Compare two answers.  

If prec is not None, it should be a positive integer
and ans1 and ans2 are regarded as double and regarded as equal
when the absolute error or the relative error is less than 10**(-prec).
If prec is None, they are compared as strings.  If ignoreSpace is True,
each line is compared with ignoring space.
'''
        # print("\nans1=", ans1, "ans2=", ans2, "prec=", prec,
        #       "ignoreSpace=", ignoreSpace, "\n", file=sys.stderr)

        if prec is None:
            if ignoreSpace:
                list1 = ans1.strip().split('\n')
                list2 = ans2.strip().split('\n')
                if len(list1) != len(list2): return False
                for (i, a) in enumerate(list1):
                    if list2[i] != a: return False
                return True
            else:
                return ans1 == ans2
        else:
            try:
                thr = 10**(-prec)
            except TypeError:
                raise UtilError("Precision should be a number.")
            if prec <= 0:
                raise UtilError("Precision should be positive.")
            ds1 = ans1.split()
            ds2 = ans2.split()
            if len(ds1) != len(ds2):
                return False
            for (a1, a2) in zip(ds1, ds2):
                if a1 == a2:
                    continue
                try:
                    d1 = float(a1)
                    d2 = float(a2)
                except ValueError:
                    return False
                ret = abs(d1 - d2) < thr or \
                      (d2 > 1.0 and abs((d1 - d2)/d2) < thr) 
                if not ret:
                    return False
            return True

    @staticmethod
    def print_answer(path):
        print(f'--{path}--')
        with open(path, encoding='utf-8') as fp:
            for line in fp:
                print(line, end='')

    @staticmethod
    def run(cmd, input=None, output=None, show_stderr=False, timeout=None):
        '''Run a process.

Returns (returncode, result).
Argument input should be None, a string, or a file descriptor.
Argument output should be None or a file descriptor.  When output
is a file descriptor, the snd of the return value (result) is None, otherwise
it is the contnets of stdout.
'''
        cp = subprocess.run(
            cmd, encoding='UTF-8', input=input,
            stdout=output or subprocess.PIPE,
            stderr=None if show_stderr else subprocess.DEVNULL,
            timeout=timeout
        )
        rc = cp.returncode
        return (rc,
                cp.stdout if (output is None and rc == 0) else None)
        
