import React, {Component} from "react";
import Input from "./Input"

class FormContainer extends Component {
    constructor() {
        super();

        this.state = {seo_title: ""};
    }

    handleChange = (event) => {
        this.setState(
            {[event.target.id]: event.target.value}
        );
    }

    handleSubmit = (event) => {
        event.preventDefault();
    }

    render() {
        const {seo_title} = this.state;
        
        return (
            <form id = "article-form" onSubmit={this.handleSubmit}>
                <Input 
                    text={seo_title ? seo_title : "Title will change"}
                    label="seo_title"
                    type="text"
                    id="seo_title"
                    value={seo_title}
                    handleChange={this.handleChange}
                />
            </form>
        );
    }
}

export default FormContainer;
