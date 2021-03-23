document.addEventListener("DOMContentLoaded", bindButtons);

function bindButtons() {
    document.getElementById("submitInfo").addEventListener("click", function(event) {
        var req = new XMLHttpRequest();
        var pasteSite = "http://httpbin.org/post";
        var payload = 
		{                       
            "food": null,
            "drink":  null
        };
        payload.food = document.getElementById("food").value;
        payload.drink = document.getElementById("drink").value;
        req.open("POST", pasteSite, true);
        req.setRequestHeader("Content-Type", "application/json");
        req.addEventListener("load",function() {
            if(req.status >= 200 && req.status < 400) {
                var response = JSON.parse(JSON.parse(req.responseText).data);
                displayResult(response);
            }
            else {
                console.log("Error");
            }
        });
        req.send(JSON.stringify(payload));
        event.preventDefault();
        
    });
}

function displayResult(response) {
    document.getElementById("returnFood").textContent = response.food;
    document.getElementById("returnDrink").textContent = response.drink;
}