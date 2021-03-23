document.addEventListener('DOMContentLoaded', binds);

function binds() {
	document.getElementById('getForecast').addEventListener('click', function(event) {
		var req = new XMLHttpRequest();
		var apiKey = "&appid=9ee30797ea89e04e4cbc1ed30aed3d2f";
		var zip = document.getElementById("zip").value;
		var city = document.getElementById("city").value;
		var payload;
		
		if (zip == 5) {
			payload = "http://api.openweathermap.org/data/2.5/weather?zip=" + zip + ",us" + apiKey + '&units=imperial';
		} else {
			payload = "http://api.openweathermap.org/data/2.5/weather?q=" + city + apiKey + '&units=imperial';
		}
		
		req.open("GET", payload, true);
		req.addEventListener('load', function() {
				if (req.status >= 200 && req.status < 400) {
					var response = JSON.parse(req.responseText);
					showWeather(response);
				} else {
					console.log("Error");
				}
		});
		
	req.send();
	event.preventDefault();
	});
}

function showWeather(response) {
	document.getElementById("temp").textContent = response.main.temp;
	document.getElementById("humidity").textContent = response.main.humidity;
	document.getElementById("windSpeed").textContent = response.wind.speed;
	document.getElementById("sunrise").textContent = response.sys.sunrise;
}