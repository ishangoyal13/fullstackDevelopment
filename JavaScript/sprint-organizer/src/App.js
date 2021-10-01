import Button from './components/Button';
import Input from './components/Input';
import List from './components/IssuesList';
import { useState } from 'react';
import { useForm } from 'react-hook-form';
import * as S from './styles/styles';
import useKnapsack from './hooks/useKnapsack';

function App() {
  const [issues, setIssues] = useState([]);
  const [tempoMax, setTempoMax] = useState(0);

  const {
    register,
    handleSubmit,
    reset,
    formState: { errors },
  } = useForm();

  const selecionadas = useKnapsack(issues, tempoMax);

  function onSubmit(data) {
    setIssues([...issues, data]);
    reset({ tempoMax });
  }

  return (
    <S.MainContainer>
      <S.Content>
        <S.Form onSubmit={handleSubmit(onSubmit)}>
          <Input
            register={register('issue', {
              validate: (value) => !issues.some((item) => item.issue === value) || 'Issue já existe!',
              required: 'Campo obrigatório!',
            })}
            placeholder="Issue"
            label="Issue"
            type="text"
            error={errors.issue}
            autoComplete="off"
          />

          <Input
            register={register('tempo', {
              validate: (value) => value > 0 || 'Tempo inválido!',
              required: 'Campo obrigatório!',
            })}
            placeholder="Tempo p/ finalizar"
            label="Tempo p/ finalizar"
            type="number"
            step="any"
            error={errors.tempo}
          />

          <Input
            register={register('dificuldade', {
              validate: (value) => value > 0 || 'Valor inválido!',
              required: 'Campo obrigatório!',
            })}
            placeholder="Dificuldade"
            label="Dificuldade"
            type="number"
            step="any"
            error={errors.dificuldade}
          />

          <Button>Adicionar</Button>

          <Input
            register={register('tempoMax', {
              validate: (value) => value > 0 || 'Valor inválido!',
            })}
            onChange={({ target: { value } }) => setTempoMax(value)}
            placeholder="Tempo de Sprint"
            label="Tempo da Sprint"
            type="number"
            step="any"
            error={errors.tempoMax}
          />
        </S.Form>

        <List issues={issues} deleteIssueCallback={setIssues} />

        <List issues={selecionadas} deleteIssueCallback={setIssues} percent />
      </S.Content>
    </S.MainContainer>
  );
}

export default App;
