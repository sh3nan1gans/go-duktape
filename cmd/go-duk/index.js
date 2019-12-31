console.log('hi');
console.log('before timeout');
setTimeout(function() {
  console.log('inside timeout');
  var id = setTimeout(function() {
    console.log('inside second timeout');
  }, 2000);
  console.log('after first', id);
  setTimeout(function() {
    console.log('inside faster timeout');
    clearTimeout(id);
  }, 1000);
}, 1000);
console.log('after timeout');
