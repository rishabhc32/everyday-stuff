import React from "react";

function Input({label, text, type, id, value, handleChange}) {
    return (
        <div className="form-group">
            <label htmlFor={label}> {text} </label>
            <input 
                type={type}
                className="form-control"
                id={id}
                value={value}
                onChange={handleChange}
                required
            />
        </div>
    );
}

export default Input;