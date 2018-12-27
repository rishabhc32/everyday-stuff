function Greetings(props) {
    return <h1>Hello, how are you?</h1>
}

function Bye(props) {
    return <h1>Bye, see you again!!</h1>
}

class Show extends React.Component {
    constructor(props) {
      super(props);
      console.log('hello');
    }

    render() {
        if(this.props.isLoggedIn) {
            return <Greetings/>;
        }
        return <Bye/>;
    }
}

class Draw extends React.Component {
    constructor(props) {
        super(props);
        this.state = {isLoggedIn: false};
    }

    handleClick = () => {
        this.setState({isLoggedIn: !this.state.isLoggedIn});
    }

    render() {
        return (
            <div>
                <Show isLoggedIn={this.state.isLoggedIn}/>
                <button onClick={this.handleClick}>Toggle</button>
            </div>
        );
    }
}

ReactDOM.render(
    <Draw/>,
    document.getElementById('root')
);