"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.URLSearchParams = exports.URL = void 0;
const _global = new Function('return this')();
let URL;
exports.URL = URL;
let URLSearchParams;
exports.URLSearchParams = URLSearchParams;
if ('URL' in _global) {
    exports.URL = URL = _global.URL;
    exports.URLSearchParams = URLSearchParams = _global.URLSearchParams;
}
else {
    exports.URL = URL = require('whatwg-url').URL;
    exports.URLSearchParams = URLSearchParams = require('whatwg-url').URLSearchParams;
}
//# sourceMappingURL=whatwg-url.js.map