/**
 * @param {string} s
 * @return {boolean}
 */
var pattern = /^[-+]?(\d+(\.(\d+)?)?|\.\d+)([eE][-+]?\d+)?$/;

var isNumber = function(s) {
    return pattern.test(s.trim());
};
