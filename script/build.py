#!/usr/bin/env python

import os
import sys
import subprocess

ROOT = os.path.abspath(os.path.dirname(os.path.dirname(__file__)))
TOOLS = os.path.join(ROOT, 'tools')


def main():
  ninja = os.path.join(TOOLS, 'depot_tools', 'ninja')
  if sys.platform == 'win32':
    ninja += '.exe'

  # TODO: Handle build types: debug, release
  build_path = os.path.join('out', 'Debug')
  ret = subprocess.call([ninja, '-C', build_path])
  if ret != 0:
    sys.exit(ret)

if __name__ == '__main__':
  sys.exit(main())
