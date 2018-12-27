class Clock extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            date: new Date(),
        };
    }

    componentDidMount() {
        this.timerID = setInterval(
            () => this.tick(),
            1000
        );
    }

    componentWillUnmount() {
        clearInterval(this.timerID);
    }

    tick() {
        this.setState({
            date: new Date()
        });
    }

    render() {
        return(
            <div>
                <h1>Hello, World!</h1>
                <h3>Time: {this.state.date.toLocaleTimeString()}</h3>
            </div>
        );
    }
}

ReactDOM.render(<Clock />, document.getElementById('root'));