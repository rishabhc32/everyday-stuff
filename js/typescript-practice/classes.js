var Student = /** @class */ (function () {
    function Student(firstName, middleName, lastName) {
        this.firstName = firstName;
        this.middleName = middleName;
        this.lastName = lastName;
        this.fullName = firstName + " " + middleName + " " + lastName;
    }
    return Student;
}());
function greet(person) {
    return "Hello " + person.firstName + " " + person.lastName;
}
var user = new Student("A", "B", "C");
document.body.innerHTML = greet(user);
