function greet(person) {
    return "Hello, " + person.firstName + " " + person.lastName;
}
var user = {
    firstName: "Rishabh",
    lastName: "Chauhan"
};
document.body.innerHTML = greet(user);
