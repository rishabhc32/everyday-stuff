import React, {Component} from "react";
import Input from './Input';

class FormContainer extends Component {
    constructor() {
        super();

        this.state = {
            title: 'hello'
        };
    }

    handleChange = (event) => {
        this.setState({
            [event.target.id]: event.target.value
        });
    }

    render() {
        const {title} = this.state;

        return (
            <form id="article-form">
                <Input 
                    text="Title"
                    label="tilte"
                    type="text"
                    id="title"
                    value={title}
                    handleChange={this.handleChange}
                />
            </form>
        );
    }
}

export default FormContainer;
