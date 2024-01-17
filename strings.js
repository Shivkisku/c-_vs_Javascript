let text1 = "HellO WorlD";
let text2 = "hello world";

// Convert text1 to uppercase and lowercase
text1 = text1.toUpperCase();
text1 = text1.toLowerCase();

// Check if text2 is in uppercase
let isUpperCase = text2 === text2.toUpperCase();

// Find the index of 'W' in text1
let indexW = text1.indexOf("W");

// Replace "HellO" with "Hi" in text1
let replacePos = text1.indexOf("HellO");
if (replacePos !== -1) {
    text1 = text1.slice(0, replacePos) + "Hi" + text1.slice(replacePos + 5);
}

// Print the results
console.log(text1);
console.log(text2);
console.log(isUpperCase);
console.log(indexW);
console.log(text1);
