function Circle(xPos, yPos, radius, xVelocity, yVelocity) {
    this.x = xPos;
    this.y = yPos;
    this.r = radius;
    this.m = 2 * Math.PI * radius;
    this.xVel = xVelocity;
    this.yVel = yVelocity;
}

Circle.prototype.move = function(second) {
    this.x += this.xVel * second;
    this.y += this.yVel * second;
};

Circle.prototype.draw = function() {
    var canvas = document.getElementById("canvas");
    var context = canvas.getContext("2d");
    context.strokeStyle = "black";
    context.beginPath();
    context.arc(this.x, this.y, this.r, 0, Math.PI * 2, true);
    context.stroke();
    context.closePath();
};

var numCircle = 5;
var width = 1000;
var height = 600;
var span = 50; 
var speedLimit = 20;

function random(low, high) {
    return low + Math.floor(Math.random() * (high - low));    
}

function genRandomCircles(nCircle) {
    var arrayCircle = [];
    for (var i = 0; i < nCircle; ++i) {
        var x = random(span, width - span);
        var y = random(span, height - span);
        var minDisToEdge = Math.min(x, y, width - x, height - y);
        var r = random(minDisToEdge / 2, minDisToEdge);
        var xVel = random(-speedLimit, speedLimit);
        var yVel = random(-speedLimit, speedLimit);
        arrayCircle.push(new Circle(x, y, r, xVel, yVel));
    }
    return arrayCircle;
}

function genCirclesTest() {
    var arrayCircle = [];
    arrayCircle[0] = new Circle(150, 150, 100, 10, 0);
    arrayCircle[1] = new Circle(800, 150, 100, -10, 0);
    return arrayCircle;
}

function genCircles() {
    var arrayCircle = [];
    var xVel = random(-speedLimit, speedLimit);
    var yVel = random(-speedLimit, speedLimit);
    arrayCircle[0] = new Circle(150, 150, 100, xVel, yVel);
    xVel = random(-speedLimit, speedLimit);
    yVel = random(-speedLimit, speedLimit);
    arrayCircle[1] = new Circle(400, 150, 120, xVel, yVel);
    xVel = random(-speedLimit, speedLimit);
    yVel = random(-speedLimit, speedLimit);
    arrayCircle[2] = new Circle(800, 150, 100, xVel, yVel);
    xVel = random(-speedLimit, speedLimit);
    yVel = random(-speedLimit, speedLimit);
    arrayCircle[3] = new Circle(100, 400, 100, xVel, yVel);
    /*xVel = random(-speedLimit, speedLimit);
    yVel = random(-speedLimit, speedLimit);
    arrayCircle[4] = new Circle(400, 400, 50, xVel, yVel);
    xVel = random(-speedLimit, speedLimit);
    yVel = random(-speedLimit, speedLimit);
    arrayCircle[5] = new Circle(800, 400, 150, xVel, yVel);*/
    return arrayCircle;
}


function Vector(x, y) {
    this.x = x;
    this.y = y;
}

Vector.prototype.len = function() {
    return Math.sqrt(this.x * this.x + this.y * this.y);
}

Vector.prototype.unit = function() {
    var len = this.len();
    this.x /= len;
    this.y /= len;
}

Vector.prototype.rotate = function(angle) {
    var x = this.x;
    var y = this.y;
    this.x = x * Math.cos(angle) + y * Math.sin(angle);
    this.y = -x * Math.sin(angle) + y * Math.cos(angle);
}

Vector.prototype.scale = function(factor) {
    var v = new Vector(this.x, this.y);
    t = factor / v.len();
    this.x *= t;
    this.y *= t; 
}

function dotProduct(vecp, vecq) {
    return vecp.x * vecq.x + vecp.y * vecq.y;
}

function calcSpeed(mp, vp, mq, vq) {
    new_vp = (2 * mq * vq + vp * (mp - mq)) / (mp + mq);
    new_vq = (2 * mp * vp + vq * (mq - mp)) / (mp + mq);
    return [new_vp, new_vq];
}

function collide(p, q) {

    if ((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y) >
        (p.r + q.r) * (p.r + q.r))
        return;

    vecp = new Vector(p.xVel, p.yVel);
    vecq = new Vector(q.xVel, q.yVel);
    
    vecs = new Vector(p.x - q.x, p.y - q.y); //圆心连线方向
    vecs.unit();
    vect = new Vector(vecs.x, vecs.y); //切线方向
    vect.rotate(Math.PI / 2);
    var vps = dotProduct(vecp, vecs);
    var vpt = dotProduct(vecp, vect);
    var vqs = dotProduct(vecq, vecs);
    var vqt = dotProduct(vecq, vect);
    var mp = p.m;
    var mq = q.m;
    var vlist = calcSpeed(mp, vps, mq, vqs);
    vps = vlist[0];
    vqs = vlist[1];
    ps = new Vector(vecs.x, vecs.y);
    ps.scale(vps);
    pt = new Vector(vect.x, vect.y);
    pt.scale(vpt);
    p.xVel = ps.x + pt.x;
    p.yVel = ps.y + pt.y;
    
    qs = new Vector(vecs.x, vecs.y);
    qs.scale(vqs);
    qt = new Vector(vect.x, vect.y);
    qt.scale(vqt);
    q.xVel = qs.x + qt.x;
    q.yVel = qs.y + qt.y;
}

function collideDetect(circles) {
    for (var i in circles) {
        var c = circles[i];
        /*if (c.x - c.r <= 0 || c.x + c.r >= width) {
            c.xVel = -c.xVel;
        }
        if (c.y - c.r <= 0 || c.y + c.r >= height) {
            c.yVel = -c.yVel;
        }*/
        if (c.x - c.r <= 0) c.xVel = Math.abs(c.xVel);
        if (c.x + c.r >= width) c.xVel = -Math.abs(c.xVel)
        if (c.y - c.r <= 0) c.yVel = Math.abs(c.yVel);
        if (c.y + c.r >= height) c.yVel = -Math.abs(c.yVel);
    }
    
    for (var i = 0; i < circles.length; ++i)
        for (var j = i + 1; j < circles.length; ++j) {
            collide(circles[i], circles[j]); 
        }
    //TODO
}

function moveCircles(circles) {
    for (var i in circles) {
        circles[i].move(1);
    }
}
function drawCircles(circles) {
    for (var i in circles) {
        circles[i].draw();
    }
}

function clearCanvas() {
    var canvas = document.getElementById("canvas");
    var context = canvas.getContext("2d");
    context.clearRect(0, 0, canvas.width, canvas.height);
}

//var arrayCircle = genRandomCircles(numCircle);
var arrayCircle = genCircles();
//var arrayCircle = genCirclesTest();

function run() {
    clearCanvas();
    moveCircles(arrayCircle);
    collideDetect(arrayCircle);
    drawCircles(arrayCircle);
}

window.onload = function () {
    var intervalTime = 50;
    setInterval(run, intervalTime);
}

