document.getElementById('addExerciseButton').addEventListener('click',function(event) {	
	var addExercise = document.getElementById("addExercise");
	var req = new XMLHttpRequest();
	var param = "exercise="+addExercise.elements.exercise.value+
				"&reps="+addExercise.elements.reps.value+
				"&weight="+addExercise.elements.weight.value+
				"&date="+addExercise.elements.date.value;
	
	// If they marked checkbox for lbs then set checkUnit to 1 (boolean value)
	if (addExercise.elements.checkUnit.checked) {
		param += "&checkUnit=1";                                     
	}
	else {
		param += "&checkUnit=0";
	}

	// Open GET request
	req.open("GET", "/insert?" + param, true);                 
	req.setRequestHeader('Content-Type','application/x-www-form-urlencoded');
	
	// Add to table once loaded
	req.addEventListener('load', function() {
		if (req.status >= 200 && req.status < 400) {
			
			// Save the response
			var response = JSON.parse(req.responseText);
			var id = response.inserted;
			
			// Save the table so that we can add to it
			var table = document.getElementById("tableOfExercises");
			var row = table.insertRow(-1);

			// Create the table and append data to it using user input
			var exerciseName = document.createElement('td');                
			exerciseName.textContent = addExercise.elements.exercise.value;
			row.appendChild(exerciseName);

			var repsCounted = document.createElement('td');
			repsCounted.textContent = addExercise.elements.reps.value;
			row.appendChild(repsCounted);

			var weightLifted = document.createElement('td');
			weightLifted.textContent = addExercise.elements.weight.value;
			row.appendChild(weightLifted);

            var dateDone = document.createElement('td');
			dateDone.textContent = addExercise.elements.date.value;
			row.appendChild(dateDone);
            
			var unitChecker = document.createElement('td');
			
			// Add lbs if specified by user, if not then kg
			if (addExercise.elements.checkUnit.checked) {                 
				unitChecker.textContent = "lbs";
			}
			else {
				unitChecker.textContent = "kg";
			}
			row.appendChild(unitChecker);
            
            // Create and add the update button and set its attributes
			var updateData = document.createElement('td');          
			var updateDataLink = document.createElement('a');
			updateDataLink.setAttribute('href','/updateTable?id=' + id);
			var updateButton = document.createElement('input');         
			updateButton.setAttribute('value','Update Exercise');       
            updateButton.setAttribute('type','button');         
			updateDataLink.appendChild(updateButton);
			updateData.appendChild(updateDataLink);
			row.appendChild(updateData);          
            
			// Create and add delete button and set its attributes
			var deleteCell = document.createElement('td');                  
			var deleteButton = document.createElement('input');             
			deleteButton.setAttribute('type','button');
			deleteButton.setAttribute('name','delete');                    
			deleteButton.setAttribute('value','Delete');
			deleteButton.setAttribute('onClick', 'deleteData("dataTable",' + id +')');
			
			// Used suggestions from assignment to handle the delete
			var deleteHidden = document.createElement('input');             
			deleteHidden.setAttribute('type','hidden');
			deleteHidden.setAttribute('id', 'delete' + id);
			deleteCell.appendChild(deleteButton);
			deleteCell.appendChild(deleteHidden);
			row.appendChild(deleteCell);
		}
		else {
	    	console.log("error");
		}
	});
	req.send("/insert?" + param);
	event.preventDefault();
});

// Function to delete data from database
function deleteData(tableId, id) {                                 
    var deleteItem = "delete" + id;    	
	var table = document.getElementById("tableOfExercises");
	// Save the table and the number of rows to use for a loop
	var numRows = table.rows.length;

	
	for (var i = 1; i < numRows; i++) {                           
		var row = table.rows[i];
		var findData = row.getElementsByTagName("td");		    
		var erase = findData[findData.length -1];		        
		if (erase.children[1].id === deleteItem) { 
			table.deleteRow(i);
		}
	}
	var req = new XMLHttpRequest();
	// Open request to delete data
	req.open("GET", "/delete?id=" + id, true);

	req.addEventListener("load",function() {
		// Confirm request worked
		if (req.status >= 200 && req.status < 400) {
	    	console.log('success');
		}
		else {
		    console.log('error');
		}
	});
	req.send("/delete?id=" + id);
}