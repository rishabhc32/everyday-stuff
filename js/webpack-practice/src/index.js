import _ from 'lodash'

let comp = _  => {
    let el = document.createElement('div')

    el.innerHTML = 'Hello'

    return el;
}

document.body.appendChild(comp())