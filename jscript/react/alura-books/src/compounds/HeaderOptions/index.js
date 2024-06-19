import styled from "styled-components";

const Options = styled.ul`
  display: flex;
`;

const Option = styled.li`
  min-width: 120px;
  font-size: 30px;
  display: flex;
  justify-content: center;
  align-items: center;
  height: 100%;
  padding: 0 5px;
  text-align: center;
  cursor: pointer;
`;

const optionsText = ["CATEGORIES", "FAVORITES", "BOOKSHELF"];
function HeaderOptions() {
  return (
    <Options>
      {optionsText.map((text) => (
        <Option><p> {text} </p></Option>
      ))}
    </Options>
  );
}

export default HeaderOptions;
