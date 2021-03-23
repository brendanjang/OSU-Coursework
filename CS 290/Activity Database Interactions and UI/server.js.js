// Some sections of the code has been referenced from the lectures and stackoverflow.
// Comments provded throughout to show understanding of the material referenced.
var express = require("express");
var app = express();
var bodyParser = require("body-parser"); 
var handlebars = require("express-handlebars").create({defaultLayout: "main"});
var mysql = require("mysql");
var pool = mysql.createPool({
   host: 'classmysql.engr.oregonstate.edu',
   user: 'cs340_jangb',
   password: '8160',
   database: 'cs340_jangb'
});

app.engine("handlebars", handlebars.engine);
app.set("view engine", "handlebars");
app.set("port", 8164);
app.use(bodyParser.urlencoded({extended: false}));
app.use(bodyParser.json());
app.use(express.static("public"));

// Given function that allows for the complete reset of a table
app.get('/reset-table',function(req,res,next) {                  
    var context = {};
    pool.query("DROP TABLE IF EXISTS workouts", function(err) {
        var createString = "CREATE TABLE workouts("+
        "id INT PRIMARY KEY AUTO_INCREMENT,"+
        "name VARCHAR(255) NOT NULL,"+
        "reps INT,"+
        "weight INT,"+
        "date DATE,"+
        "lbs BOOLEAN)";
        pool.query(createString, function(err) {
            res.render('table',context);
        })
    });
});

app.get('/', function(req, res, next) {
    var context = {};
	// Hard coded pool for convenience
    pool.query('SELECT * FROM workouts', function(err, rows, fields) {
	// Select all items in the table
    if (err) {                                                                    
        next(err);
        return;
    }
    var params = [];
	// Keep track of parameters of each item in the table
    for (var row in rows) {
        var addItem = {'name': rows[row].name, 
                    'reps': rows[row].reps, 
                    'weight': rows[row].weight, 
                    'date':rows[row].date, 
                    'id':rows[row].id};
        if (rows[row].lbs) {
            addItem.lbs = "lbs";
        }
        else {
            addItem.lbs = "kg";
        }
		// Use push to add all the parameters that we are keeping track of from above.
        params.push(addItem); 
    }
    context.results = params;
	// Show table
    res.render('table', context);
    })
});

app.get('/insert',function(req,res,next) {
  var context = {};
   pool.query("INSERT INTO `workouts` (`name`, `reps`, `weight`, `date`, `lbs`) VALUES (?, ?, ?, ?, ?)",
    [req.query.exercise,
    req.query.reps, 
    req.query.weight, 
    req.query.date, 
    req.query.checkUnit], 
    function(err, result) {
        if (err) {
          next(err);
          return;
        }         
        context.inserted = result.insertId;
        res.send(JSON.stringify(context));
  });
});

app.get('/delete', function(req, res, next) {
    var context = {};    
	// Call delete on db and require the id of item to be deleted.
    pool.query("DELETE FROM `workouts` WHERE id = ?",
        [req.query.id], 
        function(err, result) {
            if (err) {
                next(err);
                return;
            }
    });
});

app.get('/updateTable',function(req, res, next) {
    var context = {};
	// Select all items with specific id.
    pool.query('SELECT * FROM `workouts` WHERE id=?',
        [req.query.id], 
        function(err, rows, fields) {
            if (err) {
                next(err);
                return;
            }
            var param = [];
            for (var row in rows) {
                var addItem = {'name': rows[row].name, 
                            'reps': rows[row].reps, 
                            'weight': rows[row].weight, 
                            'date':rows[row].date, 
                            'lbs':rows[row].lbs,
                            'id':rows[row].id};
                param.push(addItem);
            }
		// Object needs to go to updateTable page
        context.results = param[0];
        res.render('updateTable', context);
    });
});

app.get('/updateReturn', function(req, res, next) {
    var context = {};
    pool.query("SELECT * FROM `workouts` WHERE id=?", 
        [req.query.id], 
        function(err, result) {
            if (err) {
                next(err);
                return;
            }
            if (result.length == 1) {                
                var current = result[0];
                if (req.query.checkUnit === "on") {
                    req.query.checkUnit = "1";
                }
                else {
                    req.query.checkUnit = "0";
                }
				// Query to update
                pool.query('UPDATE `workouts` SET name=?, reps=?, weight=?, date=?, lbs=? WHERE id=?',  
                [req.query.exercise || current.name, 
                req.query.reps || current.reps, 
                req.query.weight || current.weight, 
                req.query.date || current.date, 
                req.query.checkUnit, 
                req.query.id],
                function(err, result) {
                    if (err) {
                        next(err);
                        return;
                    }
                    pool.query('SELECT * FROM `workouts`', function(err, rows, fields){     
                        if (err) {
                            next(err);
                            return;
                        }
                        var param = [];
                        for (var row in rows) {
                            var addItem = {'name': rows[row].name,
                            'reps': rows[row].reps,
                            'weight': rows[row].weight, 
                            'date':rows[row].date, 
                            'id':rows[row].id};
							// Logic to differentiate between lbs and kgs
                            if (rows[row].lbs) {
                                addItem.lbs = "lbs";
                            }
                            else {
                                addItem.lbs = "kg";
                            }
							// Use push to display
                            param.push(addItem);           
                        }
                        context.results = param;
                        res.render('table', context);
                    });
                });
            }
    });
});

app.use(function(req, res) {
	res.status(404);
	res.render("404");
});

app.use(function(err, req, res, next) {
	console.log(err.stack);
	res.status(500);
	res.render("500");
});

app.listen(app.get("port"), function() {
	console.log("Express started on port 8164");
});