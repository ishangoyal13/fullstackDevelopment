import styled, { css } from 'styled-components';

export const IssueItem = styled.li`
  ${({ percent }) =>
    css`
      display: grid;
      grid-template-columns: ${!percent ? '1fr 1fr 1fr auto' : '1fr auto'};
      min-width: ${!percent ? '350px' : '100px'};
      column-gap: 1rem;
      padding: 1rem;
      border: 1px solid transparent;
      border-radius: 5px;
      box-shadow: rgba(0, 0, 0, 0.05) 0px 6px 24px 0px, rgba(0, 0, 0, 0.08) 0px 0px 0px 1px;
      transition: all 0.25s;

      &:hover {
        border: 1px solid #11998e;
        border-image: linear-gradient(to right, #11998e, #38ef7d);
        border-image-slice: 1;
      }

      span {
        display: flex;
        align-items: center;
        max-width: 155px;
        overflow-wrap: anywhere;
      }

      & span:not(:first-child) {
        display: inline-grid;
        text-align: center;
      }

      & svg {
        color: red;
        cursor: pointer;
        transition: all 0.2s;

        &:hover {
          transform: scale(1.1);
        }

        &:active {
          transform: scale(0.95);
          opacity: 0.8;
        }
      }
    `}
`;
