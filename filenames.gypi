{
  'variables': {
    'phantomjs_sources': [
      'src/app.cpp',
      'src/handler.cpp',
      'src/print_handler.cpp',
    ],
  },
  'conditions': [
    ['OS=="win"', {
      'sources/': [
        ['include', '^.*_win\\.(?:cpp|h)$'],
      ]
    }], # OS=="win"
  ],
}
