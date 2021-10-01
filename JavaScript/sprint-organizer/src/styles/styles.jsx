import styled from 'styled-components';

export const MainContainer = styled.main`
  display: grid;
  grid-template-columns: repeat(12, 1fr);
  grid-template-rows: 1fr;
  min-height: 100vh;
  padding: 3.5rem 0;
  align-items: center;
`;

export const Content = styled.div`
  display: flex;
  flex-wrap: wrap;
  grid-column: 1/-1;
  margin: 0 auto;
  row-gap: 3rem;
  column-gap: 3rem;
  padding: 3rem;
  background-color: white;
  box-shadow: 0 2.5rem 3rem -2rem hsl(200 50% 20% / 40%);
  border-radius: 10px;
`;

export const Form = styled.form`
  display: flex;
  flex-direction: column;
  gap: 2rem;

  button {
    margin: 1rem 0 2rem;
    width: 200px;
  }
`;
