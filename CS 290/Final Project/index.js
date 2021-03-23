$(".carousel").carousel();

function focusDownload(path) {
  var col = document.getElementById(path).style.backgroundColor;
  document.getElementById(path).style.backgroundColor = "grey";
  setTimeout(function() {
    document.getElementById(path).style.backgroundColor = col;
  }, 500);
}
