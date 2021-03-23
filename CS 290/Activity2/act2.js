// Write a JavaScript program that declares a function but calls it before
// it is declared. Because of function hoisting, this will work in
// JavaScript.
//
console.log(sayHello());
function sayHello() {
	return "Hello, my name is Brendan Jang.";
}

