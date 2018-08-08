interface Person {
    firstName: string;
    lastName: string;
}

function greet(person: Person) {
    return "Hello, " + person.firstName + " " + person.lastName;
}

let user = {
    firstName: "Rishabh",
    lastName: "Chauhan"
};

document.body.innerHTML = greet(user)