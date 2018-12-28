function fBorder(props) {
    return (
        <div>
            {props.children}
        </div>
    );
}

function Welcome() {
    return (
        <fBorder>
            <h1>Hello</h1>
        </fBorder>
    );
}

ReactDOM.render(<Welcome />, document.getElementById('root'));
