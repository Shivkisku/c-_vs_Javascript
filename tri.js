// Function to print a triangle with a specified height
function printTriangle(height) {
    for (let i = 1; i <= height; i++) {
      let row = '';
      // Add spaces
      for (let j = height - i; j > 0; j--) {
        row += ' ';
      }
      // Add asterisks
      for (let k = 1; k <= i * 2 - 1; k++) {
        row += '*';
      }
      console.log(row);
    }
  }
  
  // Specify the height of the triangle
  const triangleHeight = 5;
  
  // Print the triangle
  printTriangle(triangleHeight);
  