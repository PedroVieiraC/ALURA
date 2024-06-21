import { books } from "./LLDatas";
import { Title } from '../Title';
import styled from "styled-components";
import CardRecomens from "../CardRecomens";
import bookimg from '../img/livro2.png';


const LLContainer = styled.section`
  background-color: #ebecee;
  padding-bottom: 20px;
  display: flex;
  flex-direction: column;
`;


const NewBooksContainer = styled.div`
  margin-top: 30px;
  display: flex;
  width: 100%;
  justify-content: center;
  cursor: pointer;
`;

function Lastlaunchs() {
  return (
    <LLContainer>
      <Title color = '#eb9b00' fontsize='36px'> LAST LAUNCHS</Title>
      <NewBooksContainer>
        {books.map((book) => (
          <img src={book.src}></img>
        ))}
      </NewBooksContainer>
      <CardRecomens
        title = {"Maybe you like..."}
        subtitle = {'angular11'}
        desc ={'building an application integrate with the platform'}
        img = {bookimg}
      />
    </LLContainer>
  );
}

export default Lastlaunchs;
