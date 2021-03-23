/* Name: Brendan Jang
 * Date: 5/5/2019
 * Description: script.js 
 */
 
var viewTable = function() {
	  var currCol = 1;
	  var currRow = 1;
	  
	function createTable(createButton) {
		// create parts of the page
		var body = document.body;
		var table = document.createElement("table");
		var tableBody = document.createElement("tbody");
	    
		// default table style
		table.style.width = "100%";
		table.setAttribute("border", "1")
	  
		for (var i = 0; i < 4; i++) {
			// add new rows
			var tableRow = document.createElement("tr");
			for (var j= 0; j < 4; j++) {
				// add header data to rows
				if (i === 0) {
					// make header
					var tableHead = document.createElement("th");
					// add header text to header
					tableHead.appendChild(document.createTextNode("Header " + (j + 1)));
					// add header to row
					tableRow.appendChild(tableHead);
				// add data to rows
				} 
				else {
					// table data 
					var tableData = document.createElement("td");
					// create labels
					var label = (j + 1) + "," + i;
					// add label to table data
					tableData.appendChild(document.createTextNode(label));
					// set the table data id to label
					tableData.setAttribute("id", label);
					// set thicker border for starting location
					if (j === 0 && i === 1) {
						tableData.style.border = "3px solid black";
					}
					// add data to rows
					tableRow.appendChild(tableData);
				}  
			}
			// add rows to body
			tableBody.appendChild(tableRow);
		}
		// add body to table
		table.appendChild(tableBody);
		// add table to document
		body.appendChild(table);
		if (createButton) {
			createButton();
		}
	}

	function addButtons(createButton) {
		var body = document.body;
		// make array of direction button labels
		var dirLabel = ["Up", "Down", "Left", "Right", "Mark Cell"];
		for (var i = 0; i < dirLabel.length; i++) {
			var button = document.createElement("button");
			// add the coresponding label in the array to the button
			button.appendChild(document.createTextNode(dirLabel[i]));
			// add button to document body
			body.appendChild(button)
			var dir = dirLabel[i];
			// make a click event listener for each button
			button.addEventListener("click", function(e) {
				// if not marked, call separate function to mark
				if (e.target.innerText !== "Mark Cell") {
					moveCursor(e.target.innerText);
				} 
				else {
					markCell();
				}
			});
		}
	}

	// change background color of selected cell to yellow
	function markCell() {
		var cell = document.getElementById(currRow + "," + currCol);
		cell.style["background-color"] = "yellow";
	}
  
	// change the border thickness to 3 of selected cell
	function moveCursor(dir) {
		var currCellId = currRow + "," + currCol;
		var currCell = document.getElementById(currCellId);
		currCell.style.border = "1px solid black";

		// switch statement for buttons clicked
		// help received from stackoverflow
		switch (dir) {
			case "Up":
				if (currCol !== 1) {
					currCol--;
				}
				break;
			case "Down":
				if (currCol !== 3) {
					currCol++;
				}
				break;
			case "Left":
				if (currRow !== 1) {
					currRow--;
				}
				break;
			case "Right":
				if (currRow !== 4) {
					currRow++;
				}
				break;
		}
		currCellId = currRow + "," + currCol;
		currCell = document.getElementById(currCellId);
		currCell.style.border = "3px solid black";
	}
	createTable(addButtons);
};
viewTable();