import styled from "styled-components";
import { Title } from "../Title";
import bookimg from '../img/livro2.png';

const Card = styled.div`
  align-items: center;
  background-color: #fff;
  box-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25);
  border-radius: 10px;
  display: flex;
  margin: 0 auto;
  max-width: 600px;
  padding: 25px 20px;
  justify-content: space-around;
  width: 100%;
`;

const Button = styled.button`
  background-color: #eb9b00;
  color: #fff;
  padding: 10px 0px;
  font-size: 16px;
  border: none;
  font-weight: 900;
  display: block;
  text-align: center;
  width: 150px;
  &:hover {
    cursor: pointer;
  }
`;

const Desc = styled.p`
  max-width: 300px;
`;

const Subtitle = styled.h4`
  color: #002f52;
  font-size: 18px;
  font-weight: bold;
  margin: 15px 0;
`;

const Imgbook = styled.img`
  width: 150px;
`;

function CardRecomens({ title, subtitle, desc, img }) {
  return (
    <Card>
      <div>
        <Title color="#000" fontsize="16px" align="left">
          {" "}
          {title}
        </Title>
        <Subtitle>{subtitle}</Subtitle>
        <Desc>{desc}</Desc>
      </div>
      <div>
        <Imgbook src={img} />
        <Button>know more</Button>
      </div>
    </Card>
  );
}

export default CardRecomens;
