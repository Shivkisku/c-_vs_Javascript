const readline = require('readline');

const correctPin = "1234";
let balance = 1000;
let isLoggedIn = false;

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function checkPin(pin) {
  if (!isLoggedIn) {
    if (pin === correctPin) {
      isLoggedIn = true;
      console.log("PIN correct. You are now logged in.");
      showOptions();
    } else {
      console.log("Incorrect PIN. Please try again.");
      rl.close();
    }
  } else {
    console.log("You are already logged in. Logout first to enter a new PIN.");
    rl.close();
  }
}

function showOptions() {
  console.log(`Current Balance: $${balance}`);
  console.log("Select Operation:");
  console.log("1. Withdraw");
  console.log("2. Deposit");
  console.log("3. Logout");

  rl.question("Enter the number of your choice: ", (choice) => {
    switch (choice) {
      case "1":
        withdraw();
        break;
      case "2":
        deposit();
        break;
      case "3":
        logout();
        break;
      default:
        console.log("Invalid choice. Please try again.");
        showOptions();
    }
  });
}

function withdraw() {
  rl.question("Enter withdrawal amount: ", (amount) => {
    if (amount !== null && !isNaN(amount) && amount > 0 && amount <= balance) {
      balance -= parseFloat(amount);
      console.log(`Withdrawal successful. Remaining Balance: $${balance}`);
    } else {
      console.log("Invalid withdrawal amount or insufficient funds.");
    }

    showOptions();
  });
}

function deposit() {
  rl.question("Enter deposit amount: ", (amount) => {
    if (amount !== null && !isNaN(amount) && amount > 0) {
      balance += parseFloat(amount);
      console.log(`Deposit successful. Current Balance: $${balance}`);
    } else {
      console.log("Invalid deposit amount.");
    }

    showOptions();
  });
}

function logout() {
  isLoggedIn = false;
  console.log("Logged out. Please enter PIN to log in again.");
  rl.close();
}

// Example usage
rl.question("Enter your PIN: ", checkPin);
