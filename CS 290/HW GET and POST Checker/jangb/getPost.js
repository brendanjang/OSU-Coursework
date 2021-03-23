var express = require("express");
var bodyParser = require("body-parser");
var app = express();
var handlebars = require("express-handlebars").create({defaultLayout: "main"});

// Set up handlebars
app.engine("handlebars", handlebars.engine);
app.set("view engine", "handlebars");

// Set up POST processing
app.set("port", 8162);
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

// Process GET requests
app.get("/", function(req, res) {
	var qParams = [];
	for (var p in req.query) 
    {
		qParams.push({"name": p, "value": req.query[p]});   
	}
	var fill = {};
	fill.dataList = qParams;
	res.render("get", fill);                                
});

// Process POST requests
app.post("/", function(req, res) {
	var qParams = [];
	for (var p in req.query)
    {
		qParams.push({"name": p, "value": req.query[p]});   
	}
    var bParams = [];
	for (var b in req.body) 
    {
		bParams.push({"name": b, "value": req.body[b]});
	}
	var fill = {};
	fill.queryList = qParams;
    fill.bodyList = bParams;
	res.render("post", fill);                                                
});

// 404 error if page error
app.use(function(req, res) {
	res.status(404);
	res.render("404");
});

// 500 error if error in server
app.use(function(err, req, res, next) {
	console.log(err.stack);
	res.status(500);
	res.render("500");
});

app.listen(app.get("port"), function() {
	console.log("Express started on port 8160");
});
