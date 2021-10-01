import React from 'react';
import { FiDelete } from 'react-icons/fi'
import * as S from './styles';

function Card({ issue, tempo, dificuldade, deleteIssue, porcentagem }) {
  return (
    <S.IssueItem percent={porcentagem}>
      {!porcentagem ? (
        <>
          <span>{issue}</span>
          <span>{tempo}</span>
          <span>{dificuldade}</span>
          <span title="Remover issue"><FiDelete size={23} onClick={deleteIssue} /></span>
        </>
      ) : (
        <>
          <span>{issue}</span>
          <span><strong>{(porcentagem * 100).toFixed(1)}</strong></span>
        </>
      )}
    </S.IssueItem>
  );
}

export default Card;
