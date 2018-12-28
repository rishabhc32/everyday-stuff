const name = ['Sam', 'Bob', 'Butch', 'Sean'];
const listItems = name.map((name) => <li>{name}</li>);

console.log(listItems);

ReactDOM.render(
    <ul>{listItems}</ul>,
    document.getElementById('root')
);