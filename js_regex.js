var r = /\d{3}/;
r.test("hello"); // return false
r.test("123"); // return true
r.test("123ABC"); //return true
var r1 = /^\d{3}$/;
r1.test("123ABC");//return false

var s = "unicorns and rainbows and cupcakes";
var r2 = /unicorn/;
var match = s.match(r2); // return array
var r3 = /[a-z]+/gi; // flag: g: global; i: case insensitive
var result = r3.exec(s);//loop return matched regex until null
while(result != null){
    // something
    result = r3.exec(s);
}
var result1;
while (result1 = r3.exec(s)){
    // something
    console.log(result1[1]);
}

s.split(/[,.!?\s]+/);
s.split(/(\W+)/);// () will make it save into array

var s1 = "unicorns and rainbows";
s1.replace(/unicorns/, "cupcakes"); // do not change original string
s1 = s1.replace(/unicorns/g, "cupcakes");
var s2 = "unicorns and rainbows and cupcakes";
s2.replace(/([aeiou])/g,"$1$1");

s2.replace(/\b\w+\b/g,replacer);

function replacer(match) {
    return "hh";
}

s2.replace(/(\d{3})-(\d{4})/g,replacer2);

function replacer2(match, group1, group2) {
    console.log(arguments);
    return "hh";
}