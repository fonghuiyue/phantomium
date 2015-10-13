{
  'variables': {

  },
  'includes': [
    'filenames.gypi',
  ],
  'targets': [
    {
      'target_name': 'phantomjs',
      'type': 'executable',
      'dependencies': [
        '<(DEPTH)/deps/cef/cef.gyp:libcef',
        '<(DEPTH)/deps/node/node.gyp:node',
      ],
      'defines': [
        'USING_CEF_SHARED',
      ],
      'include_dirs': [
        '.',
        'src',
      ],
      'sources': [
        '<@(phantomjs_sources)'
      ],
    },
  ], # targets
}
