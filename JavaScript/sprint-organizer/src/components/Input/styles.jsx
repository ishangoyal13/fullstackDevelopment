import styled from 'styled-components';

export const InputWrapper = styled.div`
  position: relative;
  display: flex;
  flex-direction: column;
  gap: 4px;

  & span {
    position: absolute;
    top: calc(100%);
    font-size: 0.9rem;
    color: red;
  }
`;

export const InputGroup = styled.div`
  position: relative;
  padding: 15px 0 0;
  width: fit-content;
`;

export const Label = styled.label`
  position: absolute;
  top: 0;
  display: block;
  transition: 0.2s;
  font-size: 0.85rem;
  color: #9b9b9b;
`;

export const Input = styled.input`
  font-family: inherit;
  width: 100%;
  border: 0;
  border-bottom: 1px solid #9b9b9b;
  outline: 0;
  font-size: 1rem;
  color: #222;
  padding: 7px 0;
  background: transparent;
  transition: border-color 0.2s;

  &::placeholder {
    color: transparent;
  }

  &:placeholder-shown ~ ${Label} {
    font-size: 1rem;
    cursor: text;
    top: 20px;
  }

  &:focus {
    padding-bottom: 5px;
    font-weight: 700;
    border-width: 3px;
    border-image: linear-gradient(to right, #11998e, #38ef7d);
    border-image-slice: 1;

    ~ ${Label} {
      position: absolute;
      top: 0px;
      display: block;
      transition: 0.2s;
      font-size: 0.85rem;
      color: #11998e;
      font-weight: 700;
    }
  }

  &:required,
  &:invalid {
    box-shadow: none;
  }
`;
