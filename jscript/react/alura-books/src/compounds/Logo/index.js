import './style.css'
import logo from '../img/logo.svg'

function Logo() {
    return (
        <div className = 'logo'>
            <img src = {logo}
            alt = 'logo'
            className = 'img-logo'
            ></img>
            <p><strong> Alura books </strong></p>
        </div>
    )
}

export default Logo;