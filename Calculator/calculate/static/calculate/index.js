'use strict';

alert("Welcome To calculator");

function say(){
	alert("hello");
}

function calcul(){
	var text = document.getElementById('input').value;
	alert(text + " new text");
}

// window.result = document.getElementById("result");
// window.input1 = document.getElementById("input1").value;
// window.input2 = document.getElementById("input2").value;

function add_(){
	var result = document.getElementById("result");
	var input1 = document.getElementById("input1").value;
	var input2 = document.getElementById("input2").value;

	// alert(parseInt(input1, 10) + parseInt(input2, 10));
	result.innerHTML = parseInt(input1, 10) + parseInt(input2, 10);
}

function sub_(){
	var result = document.getElementById("result");
	var input1 = document.getElementById("input1").value;
	var input2 = document.getElementById("input2").value;

	// alert(parseInt(input1, 10) - parseInt(input2, 10));
	result.innerHTML = parseInt(input1, 10) - parseInt(input2, 10);
}

function mult_(){
	var result = document.getElementById("result");
	var input1 = document.getElementById("input1").value;
	var input2 = document.getElementById("input2").value;

	// alert(parseInt(input1, 10) * parseInt(input2, 10));
	result.innerHTML = parseInt(input1, 10) * parseInt(input2, 10);
}

function div_(){
	var result = document.getElementById("result");
	var input1 = document.getElementById("input1").value;
	var input2 = document.getElementById("input2").value;

	// alert(parseInt(input1, 10) / parseInt(input2, 10));
	result.innerHTML = parseInt(input1, 10) / parseInt(input2, 10);
}
