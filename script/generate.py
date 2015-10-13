#!/usr/bin/env python

import os
import sys
import subprocess


ROOT = os.path.abspath(os.path.dirname(os.path.dirname(__file__)))
TOOLS = os.path.join(ROOT, 'tools')
GYP = os.path.join(TOOLS, 'gyp', 'gyp_main.py')

def main():
  env = os.environ.copy()
  gyp_pylib = os.path.join(os.path.dirname(GYP), 'pylib')
  env['PYTHONPATH'] = os.path.pathsep.join([gyp_pylib, env.get('PYTHONPATH', '')])

  if sys.platform == 'win32':
    env['DEPOT_TOOLS_WIN_TOOLCHAIN'] = '0'
    env['GYP_GENERATORS'] = 'ninja'

  return subprocess.call([
    sys.executable,
    GYP,
    '--depth', '.',
    'phantomjs.gyp'], env=env)


if __name__ == '__main__':
  sys.exit(main())
