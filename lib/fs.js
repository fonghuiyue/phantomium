(function() {
  'use strict';

  var fs;
  if (!fs) {
    fs = {};
  }

  fs.open = function(path, options) {
    native function open();
    if (path) return open(path);
    else if (path && options) return open(path, options);
  };

})();
