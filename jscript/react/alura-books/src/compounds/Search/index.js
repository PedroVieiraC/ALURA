import Input from "../Input";
import styled from "styled-components";
import { useState } from "react";
import { books } from "./searchDatas";

const SearchContainer = styled.section`
  background-image: linear-gradient(90deg, #002f52 35%, #326589 165%);
  color: #fff;
  text-align: center;
  padding: 85px 0;
  min-height: 270px; /* Define uma altura mínima */
  width: 100%;
  overflow: auto; /* Garante que o contêiner expanda com o conteúdo */
`;

const Title = styled.h2`
  color: #fff;
  font-size: 36px;
  text-align: center;
  width: 100%;
`;

const Subtitle = styled.h3`
  font-size: 16px;
  font-weight: 500;
  margin-bottom: 40px;
`;

const Result = styled.div`
  display: flex;
  justify-content: center;
  align-items: center;
  margin-bottom: 20px;
  cursor: pointer;
  p {
    width: 200px;
  }
  img {
    width: 100px;
  }
  &:hover {
    border: 1px solid white;
  }
`;

function Search() {
  const [searchBooks, setSearchedBooks] = useState([]);

  const handleSearch = (event) => {
    const wroteText = event.target.value;
    if (wroteText.trim() === "") {
      setSearchedBooks([]);
    } else {
      const searchResult = books.filter((book) =>
        book.name.toLowerCase().includes(wroteText.toLowerCase())
      );
      setSearchedBooks(searchResult);
    }
  };

  return (
    <SearchContainer>
      <Title>Already know where to start?</Title>
      <Subtitle>Find your book in our bookshelf.</Subtitle>
      <Input placeholder="Write your next lecture" onChange={handleSearch} />
      {searchBooks.map((book, index) => (
        <Result key={index}>
          <p>{book.name}</p>
          <img src={book.src} alt={book.name} />
        </Result>
      ))}
    </SearchContainer>
  );
}

export default Search;
