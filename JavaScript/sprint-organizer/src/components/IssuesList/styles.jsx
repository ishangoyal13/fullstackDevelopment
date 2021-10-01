import styled, { css } from 'styled-components';

export const ListContainer = styled.div`
  display: flex;
  flex-direction: column;
  min-width: 330px;
  height: 450px;
  gap: 1rem;
  overflow-y: auto;
  align-items: center;
  margin: 0px -1rem;
  padding: 0px 1rem;
`;

export const List = styled.ul`
  display: flex;
  flex-direction: column;
  row-gap: 1.35rem;
  list-style: none;
  padding: 0;
  margin: 0;
  width: 100%;
`;

export const Header = styled.div`
  ${({ percent }) =>
    css`
      position: relative;
      display: grid;
      grid-template-columns: ${!percent ? '1fr 1fr 1fr auto' : '1fr auto'};
      width: 100%;
      color: #666;
      margin-top: 32px;

      & span:first-child {
        position: absolute;
        top: -26px;
        left: 50%;
        transform: translate(-50%, 0);
        font-weight: 600;
      }

      & span:nth-child(n+3) {
        display: inline-grid;
        text-align: center;
      }

      ${percent && css`
        & span:nth-child(3) {
          margin-right: 1.75rem;
        }
      `}
    `}
`;
