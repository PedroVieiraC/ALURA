import './style.css';

const optionsText = ["CATEGORIES", "FAVORITES", "BOOKSHELF"];
function HeaderOptions(){
    return (
    <ul className="Options">
        {optionsText.map((text) => (
          <li className="Option"> {text} </li>
        ))}
      </ul>
    )
}

export default HeaderOptions;