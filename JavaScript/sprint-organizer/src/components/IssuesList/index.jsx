import React from 'react';
import IssueItem from '../IssueItem';
import * as S from './styles';

function List({ issues, deleteIssueCallback, percent = false }) {
  const removeIssue = (issueToRemove) => deleteIssueCallback(issues.filter((issue) => issue.issue !== issueToRemove));

  return (
    <S.ListContainer>
      <S.Header percent={percent}>
        {!percent ? <span>Backlog</span> : <span>Sprint Backlog</span>}
        <span>Nome</span>
        {!percent && <span>Tempo</span>}
        {!percent && <span>Dificuldade</span>}
        {percent && <span>%</span>}
      </S.Header>
      <S.List>
        {issues.map((item) => (
          <IssueItem key={item.issue} {...item} deleteIssue={() => removeIssue(item.issue)} />
        ))}
      </S.List>
    </S.ListContainer>
  );
}

export default List;
