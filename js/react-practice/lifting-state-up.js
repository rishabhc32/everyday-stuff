function BoilingVerdict(props) {
    if (props.celsius >= 100) 
        return <p>Waater will boil.</p>;
    
    return <p>Water will not boil</p>
}

class TemperatureInput extends React.Component {
    constructor(props) {
        super(props);
    }

    handleChange = (event) => {
        this.props.onTempChange(event.target.value);
    }

    render() {
        const temp = this.props.temp;
        const scale = this.props.scale;

        return (
            <fieldset>
                <legend>Enter temp in {scale}:</legend>
                <input value={temp} onChange={this.handleChange} />
            </fieldset>

        );
    }
}

class Calculator extends React.Component {
    constructor(props) {
        super(props);
        this.state = {temp: '', scale: 'Celcius'};
    }

    handleCelsiusChange = (temp) => {
        this.setState({temp: temp, scale: 'Celsius'});
    }

    handleFahrenheitChange = (temp) => {
        this.setState({temp: temp, scale: 'Fahrenheit'});
    }

    render() {
        const temp = this.state.temp;
        const scale = this.state.scale;
        const C = scale === 'Fahrenheit' ? tryConvert(temp, toCelsius) : temp;
        const F = scale === 'Celsius' ? tryConvert(temp, toFahrenheit) :temp;
 
        return (
            <div>
                <TemperatureInput scale="Celsius" temp={C} onTempChange={this.handleCelsiusChange} />
                <TemperatureInput scale="Fahrenheit" temp={F} onTempChange={this.handleFahrenheitChange} />
                <BoilingVerdict celsius={parseFloat(C)} />
            </div>
        );
    }
}

ReactDOM.render(
    <Calculator />, document.getElementById('root')
);

function tryConvert(temp, convertFunction) {
    const input = parseFloat(temp);
    if(Number.isNaN(input))
        return '';
    
    const ouput = convertFunction(input);
    const rounded = Math.round(ouput * 1000) / 1000;
    return rounded.toString();
}

function toCelsius(fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}
  
function toFahrenheit(celsius) {
return (celsius * 9 / 5) + 32;
}