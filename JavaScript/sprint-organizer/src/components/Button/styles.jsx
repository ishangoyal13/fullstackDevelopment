import styled from 'styled-components';

export const Button = styled.button`
  position: relative;
  display: inline-flex;
  padding: 12px 24px;
  cursor: pointer;
  user-select: none;
  transition: 0.25s;
  align-items: center;
  justify-content: center;
  color: #f5f5f5;
  background: #11998e;
  font-size: 1.1rem;
  font-weight: bold;
  text-transform: uppercase;
  letter-spacing: 1px;
  border: none;

  &:hover {
    /* box-shadow: 0 20px 25px -15px rgb(0 0 0 / 25%); */
  }

  &:active {
    opacity: 0.8;
  }

  &:after {
    position: absolute;
    content: '';
    display: block;
    top: 0;
    left: 0;
    right: 0;
    bottom: 0;
    border: 3px solid #11998e;
    transition: all 0.2s;

    transition-timing-function: cubic-bezier(0.69, 0, 0, 1) !important;
    animation-timing-function: cubic-bezier(0.69, 0, 0, 1) !important;
  }

  &:hover {
    &:after {
      top: -5px;
      left: -5px;
      right: -5px;
      bottom: -5px;
      border-image: linear-gradient(to right, #11998e, #38ef7d);
      border-image-slice: 1;
    }
  }
`;
