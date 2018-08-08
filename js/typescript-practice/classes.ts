class Student {
    fullName: string;

    constructor(public firstName: string, public middleName: string, public lastName: string) {
        this.fullName = firstName + " " + middleName + " " + lastName;
    }
}

interface Person {
    firstName: string;
    lastName: string;
}

function greet(person: Person) {
    return "Hello " + person.firstName + " " + person.lastName;
}

let user = new Student("A", "B", "C");

document.body.innerHTML = greet(user);
