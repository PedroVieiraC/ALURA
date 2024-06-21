import Header from "./compounds/Header";
import styled from "styled-components";
import Search from "./compounds/Search";
import Lastlaunchs from "./compounds/LastLaunchs";

const AppContainer = styled.div`
  width: 100vw;
  height: 100vw;
  background-image: linear-gradient(90deg, #002f52 35%, #326589);
`;

function App() {
  return (
    <AppContainer>
      <Header />
      <Search />
      
      <Lastlaunchs />
    </AppContainer>
  );
}

export default App;
